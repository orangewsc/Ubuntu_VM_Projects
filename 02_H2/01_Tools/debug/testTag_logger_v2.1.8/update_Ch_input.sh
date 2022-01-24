#!/bin/bash

#change history
#2020-05-07,xjm, v2.0.3


gbError="\033[31m[Error]\033[0m"
gbWarning="\033[33m[Warning]\033[0m"
gbInfo="\033[32m[Info]\033[0m"

gbOrgLib="libfcitxplatforminputcontextplugin.so"

gbOrgPath="/usr/lib/x86_64-linux-gnu/qt5/plugins/platforminputcontexts"

gbOrgLibPath=$gbOrgPath/$gbOrgLib

#for Qt UI Chinese input
gbDesPath="/opt/Qt5.5.1/5.5/gcc_64/plugins/platforminputcontexts"
gbDesLibPath=$gbDesPath/$gbOrgLib

gbDesCreatorPath="/opt/Qt5.5.1/Tools/QtCreator/bin/plugins/platforminputcontexts"
gbDesCreatorLibPath=$gbDesCreatorPath/$gbOrgLib

gbFcitxFrontendQt5Path=$gbOrgPath
gbFcitxFrontendQt5LibPath=$gbFcitxFrontendQt5Path/$gbOrgLib


gbIsEarlyVersion=0
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
    gbPreLib="./lib-ubuntu14.04"
    gbIsEarlyVersion=1
  elif [ x"$verShort" == x"16.04" ];then
    gbPreLib="./lib-ubuntu16.04"
  else
    echo -e "$gbWarning not prepare $sys $version lib, no lib for it"
    return 1
  fi 
  
  echo -e "$gbInfo prepare lib path is $gbPreLib, system is $sys $version"  
  return 0
}

check_org_lib()
{

  check_ubuntu_version
  if [ $? -eq 1 ];then
    return 1
  fi

  if [ $gbIsEarlyVersion -eq 1 ];then
     gbOrgLibPath=$gbPreLib"/"$gbOrgLib
  else
    if [ ! -f "$gbOrgLibPath" ];then  
      echo -e "$gbError Not find $gbOrgLibPath, will use current $gbPreLib file"
      gbOrgLibPath=$gbPreLib"/"$gbOrgLib 
    else
      echo -e "$gbInfo find $gbOrgLibPath"
    fi
  fi

  if [ ! -f "$gbOrgLibPath" ];then
     echo -e "$gbError Not find $gbOrgLibPath"
     return 1
  else
    echo -e "$gbInfo find $gbOrgLibPath"
  fi

  
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
      
      gbDesPath=${val%/*}"/plugins/platforminputcontexts"
      echo -e "$gbInfo: find Qt_lib path is $val, set Ch_input lib path is $gbDesPath"
      break;      
    fi
  done
  gbDesLibPath=$gbDesPath/$gbOrgLib
  
  #find qt bin path
  local qtbinPath=`which qtcreator`
  if [ -z "$qtbinPath" ];then
    echo -e "$gbError not find qtcreator path, please check"
    return 1
  fi
  
  gbDesCreatorPath=${qtbinPath%/*}"/plugins/platforminputcontexts"
  gbDesCreatorLibPath=$gbDesCreatorPath/$gbOrgLib
  
  return 0
}

copy_lib()
{
  local desPath="$1"
  local orgPath="$2"
  if [ -f "$desPath" ];then
    echo -e "$gbWarning Already has $desPath, rename it to $gbOrgLib-backup"
    cp $desPath $desPath-backup
    if [ $? -ne 0 ];then
      echo -e "$gbError copy $desPath to $desPath-backup error, use sudo to try again."
      return  1
    else
      echo -e "$gbInfo copy $desPath to $desPath-backup ok"
    fi
  fi

  operate_copy $desPath $orgPath
  if [ $? -eq 1 ];then
    return 1
  fi

  return 0
}

operate_copy()
{
  local desPath="$1"
  local orgPath="$2"

  diff $orgPath $desPath
  if [ $? -ne 0 ];then
    echo -e "$gbWarning $orgPath and $desPath are different, try to copy"
    cp $orgPath $desPath
    if [ $? -ne 0 ];then
      echo -e "$gbError copy $orgPath to $desPath error, use sudo to try again."
      return 1
    else
      echo -e "$gbInfo copy $orgPath to $desPath ok"
    fi    
  else
    echo -e "$gbInfo $orgPath and $desPath are the same, no need copy"
  fi
  sudo chmod 644 $desPath

  return 0

}

make_softlink()
{
  local desPath="$1"
  local linkName="$2"
  local libName="$3"

  if [ -f "$desPath"/"$linkName" ];then
    echo -e "$gbWarning find $desPath/$linkName, try to remove it"
    rm -rf $desPath"/"$linkName
    if [ $? -ne 0 ];then
      echo -e "$gbError remove $desPath/$linkName error"
      return 1
    else
      echo -e "$gbInfo remove $desPath/$linkName ok"
    fi  
  fi

  ln -s $desPath"/"$libName $desPath"/"$linkName
  if [ $? -ne 0 ];then
    echo -e "$gbError make softlink $desPath/$linkName error"
    return 1
  else
    echo -e "$gbInfo make softlink $desPath/$linkName ok"
  fi

  return 0
}

copy_related_lib()
{
  if [ $gbIsEarlyVersion -eq 0 ];then
    return 0
  fi

  local libName="lib-related.tar.gz"
  local reLib=$gbPreLib"/"$libName

  local desPath="/usr/lib/x86_64-linux-gnu/"

  if [ ! -f "$reLib" ];then
    echo -e "$gbError not find $reLib"
    return 1
  fi

  tar -xzf $reLib -C $desPath
  if [ $? -ne 0 ];then
    echo -e "$gbError untar $reLib error"
    return 1
  else
    echo -e "$gbInfo untar $reLib ok"
  fi


  return 0
}


check_org_lib
if [ $? -eq 1 ];then
  exit 1
fi

get_qt_path
if [ $? -eq 1 ];then
  exit 1
fi

copy_lib $gbDesLibPath $gbOrgLibPath
if [ $? -eq 1 ];then
  exit 1
fi

copy_lib $gbDesCreatorLibPath $gbOrgLibPath
if [ $? -eq 1 ];then
  exit 1
fi

copy_lib $gbFcitxFrontendQt5LibPath $gbOrgLibPath
if [ $? -eq 1 ];then
  exit 1
fi

copy_related_lib
if [ $? -eq 1 ];then
  exit 1
fi

ldconfig
echo -e "$gbInfo restart, retry Chinese input, it will be ok."

exit 1

