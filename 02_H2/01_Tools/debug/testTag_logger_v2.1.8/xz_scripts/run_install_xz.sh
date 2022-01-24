#!/bin/bash


gbError="\033[31m[Error]\033[0m"
gbWarning="\033[33m[Warning]\033[0m"
gbInfo="\033[32m[Info]\033[0m"


#gbInstallType: 0 install, 1 copy files
gbInstallType=0

if [ ! -z $1 ];then
  echo -e "$gbInfo input arg1: $1"
  gbInstallType=$1
fi
echo -e "$gbInfo install type is $gbInstallType (0 install xz-5.2.2, 1 copy precomplied files)"

gbRestart=0

gbSysVersion14=0
gbPreCompileDir="."
check_ubuntu_version()
{
  local sys=`cat /etc/issue | awk '{print $1}'`
  
  if [ x"$sys" != x"Ubuntu" ];then
    echo -e "$gbError system is $sys, not ubuntu, no related lib for chinese input, please install manully"
    return 1
  fi
  
  local version=`cat /etc/issue | awk '{print $2}'`  
  local verShort=`echo ${version:0:5}`  

  if [ x"$verShort" == x"14.04" ];then
    gbPreCompileDir="./xz-ubuntu14.04"
    gbSysVersion14=1
  elif [ x"$verShort" == x"16.04" ];then
    gbPreCompileDir="./xz-ubuntu16.04"
  else
    echo -e "$gbWarning arg should be install"
  fi 
  
  echo -e "$gbInfo prepare compiled directory is $gbPreCompileDir, system is $sys $version"  
  return 0
}


check_xz_version()
{
  local version=`xz --version | head -n 1 | awk '{print $NF}'`
  echo -e "$gbInfo current xz version:"
  xz --version
  echo "xz version: $version "


  if [ x"$version" == x"" ];then
    echo -e "gbError xz not find, need install 5.2 or 5.2+"
    return 2
  fi
 
  local v1=`echo ${version} | awk -F '.' '{print $1}'`
  local v2=`echo ${version} | awk -F '.' '{print $2}'`


  echo "version v1: $v1 v2: $v2 "


  if [ $v1 -eq 5 ];then
    if [ $v2 -lt 2 ];then
       echo -e "$gbWarning current is lower than 5.2, need install 5.2 or 5.2+"
       return 2
    else
       echo -e "$gbInfo current is higner than 5.2, check version ok."
       return 0
    fi
  elif [ $v1 -lt 5 ];then
    echo -e "$gbWarning current is lower than 5.2, need install 5.2 or 5.2+"
    return 2
  else
    echo -e "$gbInfo current is higner than 5.2, check version ok."
    return 0
  fi   

  return 0
}


install_new_xz()
{
  local pkgName="xz-5.2.2.tar.gz"
  if [ -f "$pkgName" ];then
    echo -e "$gbInfo find $pkgName"
  else
    echo -e "$gbError not find $pkgName"
    return 1
  fi

  local fileDir="xz-5.2.2"
  if [ -d "$fileDir" ];then
    echo -e "$gbWarning find old $fileDir directory, try to remove it"
    rm -rf $fileDir
    if [ $? -ne 0 ];then
      echo -e "$gbError remove $fileDir directory error"
      return 1
    else
      echo -e "$gbInfo remove $fileDir directory ok"
    fi
  else
    echo -e "$gbInfo not find old $fileDir directory" 
  fi

  tar -xzf $pkgName
  if [ $? -ne 0 ];then
    echo -e "$gbError tar -xzf $fileName error"
    return 1
  else
    echo -e "$gbInfo tar -xzf $fileName ok"
  fi

  pushd ./$fileDir

  ./configure

  make
  
  sudo make install
  

  return 0

}


copy_xz_files()
{
  local pkgDesFile="$gbPreCompileDir/xz-5.2.2-files.tar.gz"

  echo -e "$gbInfo this script will install xz 5.2.2 files to system, based on ubuntu 16.04"

  echo -e "$gbInfo try to copy xz files to system"  

  if [ ! -f "$pkgDesFile" ];then
    echo -e "gbError not find $pkgDesFile file"
    return 1
  fi

  sudo tar -xzf $pkgDesFile -C /
  if [ $? -ne 0 ];then
    echo -e "$gbError \"sudo tar -xzf $pkgDesFile -C /\" error"
    return 1
  else
    echo -e "$gbInfo \"sudo tar -xzf $pkgDesFile -C /\" ok"
  fi

  return 0
}

check_set_env()
{
  # check env

  local envFile=`ls ~/.profile`
  if [ ! -f "$envFile" ];then
    echo -e "$gbError not find $envFile, please check"
    return 1
  fi

  source $envFile

  local xzPath="/usr/local/bin"
  local envName="PATH"
  check_env $xzPath $envName
  if [ $? -eq 1 ];then
    echo -e "$gbError check_env [set] $envName, error"
    return 1
  else
    echo -e "$gbInfo check_env [set] $envName, ok"
  fi


  local xzLibPath="/usr/local/lib"
  envName="LD_LIBRARY_PATH"
  check_env $xzLibPath $envName
  if [ $? -eq 1 ];then
    echo -e "$gbError check_env [set] $envName, error"
    return 1
  else
    echo -e "$gbInfo check_env [set] $envName, ok"
  fi

  #ldconfig
  return 0
}


check_env()
{
  if [ -z $1 ];then
    echo -e "$gbError check_env arg1 is null"
    return 1
  fi

  if [ -z $2 ];then
    echo -e "$gbError check_env arg2 is null"
    return 1
  fi

  local xzPath="$1"
  local EnvParameter="$2"

  local xzBin=`which xz`

  local cmd="ldd $xzBin | grep \"liblzma.so.5 => /usr/local/lib/liblzma.so.5\""
  if [ x"$EnvParameter" == x"PATH" ];then
    cmd="which xz | grep \"/usr/local/bin/xz\""
  fi    
     
  local chk2=`eval $cmd`
  if [ x"$chk2" != x"" ];then
    echo -e "$gbInfo \"$cmd\", check ok"
  else
    echo -e "$gbWarning \"$cmd\", check error"

    local chk1=`echo $$EnvParameter | grep $xzPath`
    if [ x"$chk1" != x"" ];then 
      echo -e "$gbInfo find $xzPath in $EnvParameter, maybe pos is not ok, reset it"      
      set_profile $xzPath $EnvParameter 1
      if [ $? -eq 1 ];then
        echo -e "$gbError set_profile error"
        return 1
      fi    
    else
      echo -e "$gbError not find $xzPath in $EnvParameter, next set it"
      set_profile $xzPath $EnvParameter 0
      if [ $? -eq 1 ];then
        echo -e "$gbError set_profile error"
        return 1
      fi
    fi
  fi

  return 0
}


set_profile()
{
  if [ -z $1 ];then
    echo -e "$gbError set_profile arg1 is null"
    return 1
  fi

  if [ -z $2 ];then
    echo -e "$gbError set_profile arg2 is null"
    return 1
  fi

  local xzPath="$1"
  local EnvParameter="$2"

  local setBefore=0
  if [ ! -z $3 ];then
    setBefore=1   
  fi
  echo -e "$gbInfo set env pos is $setBefore (0 begin, 1 end)"


  #local envFile="/home/`whoami`/.profile"   
  local envFile=`ls ~/.profile`
  if [ ! -f "$envFile" ];then
    echo -e "$gbError not find $envFile, please check"
    return 1
  else
    echo -e "\n#for xz" >> $envFile
    if [ $setBefore -eq 1 ];then
      echo -e "export $EnvParameter=\$$EnvParameter:$xzPath\n" >> $envFile
    else
      echo -e "export $EnvParameter=$xzPath:\$$EnvParameter\n" >> $envFile
    fi
    
    source $envFile
    local cmd="echo \$$EnvParameter | grep $xzPath"
    local chkEnv2=`eval $cmd`
    if [ x"$chkEnv2" != x"" ];then 
      gbRestart=1
      echo -e "$gbInfo check $xzPath in $EnvParameter ok, please restart system"
      return 0
    else
      echo -e "$gbError check $xzPath in $EnvParameter error, please check"
      return 1
    fi
  fi
  return 0
}


main()
{
  check_ubuntu_version
  if [ $? -eq 1 ];then
    return 1
  fi

  check_xz_version
  local res=$?
  if [ $res -eq 2 ];then

    echo -e "$gbInfo gbInstallType is $gbInstallType"
    if [ $gbInstallType -eq 0 ];then
      install_new_xz 
      if [ $? -eq 1 ];then
        echo -e "$gbError install_new_xz error"
        return 1
      else
        echo -e "$gbInfo install_new_xz ok"
      fi 
    elif [ $gbInstallType -eq 1 ];then
      copy_xz_files 
      if [ $? -eq 1 ];then
        echo -e "$gbError copy_xz_files error"
        return 1
      else
        echo -e "$gbInfo copy_xz_files ok"
      fi
    else
      echo -e "$gbError gbInstallType is $gbInstallType, not 0 or 1, please check"
      return 1
    fi
  fi

  check_set_env
  if [ $? -eq 1 ];then
    echo -e "$gbError check_set_env error"
    return 1
  else
    echo -e "$gbInfo check_set_env ok"
  fi  


  check_xz_version
  if [ $? -eq 0 ];then
    echo -e "$gbInfo double check_xz_version ok"
  else
    echo -e "$gbError double check_xz_version error"
    return 1
  fi

  if [ $gbRestart -eq 1 ];then
    echo -e "$gbInfo check $xzPath in PATH ok, please restart system"
  fi

  return 0
}
      


main
exit $?




