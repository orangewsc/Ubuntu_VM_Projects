#!/bin/bash


gbError="\033[31m[Error]\033[0m"
gbWarning="\033[33m[Warning]\033[0m"
gbInfo="\033[32m[Info]\033[0m"


#gbInstallType: 0 install, 1 copy files
#gbInstallType=0

#if [ ! -z $1 ];then
#  echo -e "$gbInfo input arg1: $1"
#  gbInstallType=$1
#fi
#echo -e "$gbInfo install type is $gbInstallType (0 install xz-5.2.2, 1 copy precomplied files)"

#gbRestart=0

gbSysVersion14=0
gbPreCompileDir="."

gbDesPath="/opt/Qt5.5.1/5.5/gcc_64/lib/"

check_ubuntu_version()
{
  local sys=`cat /etc/issue | awk '{print $1}'`
  
  if [ x"$sys" != x"Ubuntu" ];then
    echo -e "$gbError system is $sys, not ubuntu, please check"
    return 1
  fi
  
  local version=`cat /etc/issue | awk '{print $2}'`  
  local verShort=`echo ${version:0:5}`  

  if [ x"$verShort" == x"14.04" ];then
    gbPreCompileDir="./ubuntu14_openssl1.0_lib"
    gbSysVersion14=1
  elif [ x"$verShort" == x"16.04" ];then
    gbPreCompileDir="./ubuntu16_openssl1.0_lib"
  else
    echo -e "$gbWarning arg should be install"
  fi 
  
  echo -e "$gbInfo prepare compiled directory is $gbPreCompileDir, system is $sys $version"  
  return 0
}


get_qt_path()
{
  if [ -d "$gbDesPath" ];then
    echo -e "$gbInfo find $gbDesPath directory"
    return 0
  fi  

  #find qt path
  local lib_path=`echo $LD_LIBRARY_PATH` 
  OLD_IFS="$IFS"
  IFS=":"
  arr=($lib_path)
  ver_len=${#arr[@]}

  for val in ${arr[@]}; do
    local chk=`echo $val | grep gcc_64 | grep Qt`
    if [ ! -z $chk ];then      
      gbDesPath=${val%/*}
      echo -e "$gbInfo: find Qt_lib path is $val"
      break;      
    fi
  done

  
  #find qt bin path
  local qtbinPath=`which qtcreator`
  if [ -z "$qtbinPath" ];then
    echo -e "$gbError not find qtcreator path, please check"
    return 1
  fi
  
 
  return 0
}

install_new_ssl()
{
  local pkgName="openssl-OpenSSL_1_0_2-stable.tar.gz"
  if [ -f "$pkgName" ];then
    echo -e "$gbInfo find $pkgName"
  else
    echo -e "$gbError not find $pkgName"
    return 1
  fi

  local fileDir="openssl-OpenSSL_1_0_2-stable"
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

  ./config enable-shared

  #make depend

  make -j4 
  
  echo -e "$gbInfo try to cp libssl* libcrypto* to $gbDesPath"
  sudo cp libssl* libcrypto* $gbDesPath
  if [ $? -ne 0 ];then
    echo -e "$gbError cp libssl* libcrypto* $gbDesPath error"
    return 1
  else
    echo -e "$gbInfo cp libssl* libcrypto* $gbDesPath ok"
  fi

  tar -czf lib_res.tar.gz libssl* libcrypto* 
  cp lib_res.tar.gz ..

  pushd

  echo -e "$gbInfo try to remove $fileDir"
  rm -rf $fileDir
  if [ $? -ne 0 ];then
    echo -e "$gbError remove $fileDir error"
    return 1
  else
    echo -e "$gbInfo remove $fileDir ok"
  fi

  sudo ldconfig

  return 0

}


copy_ssl_files()
{
  local pkgDesFile="$gbPreCompileDir/openssl1.0_lib.tar.gz"

  echo -e "$gbInfo try to copy ssl lib files to $gbDesPath"  

  if [ ! -f "$pkgDesFile" ];then
    echo -e "gbError not find $pkgDesFile file"
    return 1
  fi

  sudo tar -xzf $pkgDesFile -C $gbDesPath
  if [ $? -ne 0 ];then
    echo -e "$gbError \"sudo tar -xzf $pkgDesFile -C $gbDesPath\" error"
    return 1
  else
    echo -e "$gbInfo \"sudo tar -xzf $pkgDesFile -C $gbDesPath\" ok"
  fi

  sudo ldconfig

  return 0
}

main()
{
  check_ubuntu_version
  if [ $? -eq 1 ];then
    return 1
  fi

  get_qt_path
  if [ $? -eq 1 ];then
    return 1
  fi

  copy_ssl_files
  if [ $? -eq 1 ];then
    return 1
  fi

  return 0
}

backup()
{
  install_new_ssl 
  if [ $? -eq 1 ];then
    echo -e "$gbError install_new_ssl error"
    return 1
  else
    echo -e "$gbInfo install_new_ssl ok"
  fi     

  return 0
}
      


main
exit $?




