#!/bin/bash

# tar .log to .tar.xz


gbError="\033[31m[Error]\033[0m"
gbWarning="\033[33m[Warning]\033[0m"
gbInfo="\033[32m[Info]\033[0m"



make_tar_log()
{
  echo -e "$gbInfo this script will tar .log to .tar.xz in current path"

  gbLogs=$(ls  *.log)

  #gbLogCnt=${#gbLogs[*]}
  gbLogCnt=0
  for logFile in $gbLogs; do
    ((gbLogCnt++))
  done


  if [ $gbLogCnt -eq 0 ];then
    echo -e "$gbWarning not find .log file"
    return 0
  else 
    echo -e "$gbInfo .log file count is $gbLogCnt"
  fi

  #gbXzNew: 1 xz 5.2+, 0 5.1-
  gbXzNew=1

  ##tar -cJf 1.tar.gz $file

  #for logFile in "${gbLogs[@]}"; do
  for logFile in $gbLogs; do

    local preLogName=${logFile%.log*}

    if [ -f "$preLogName.tar.xz" ];then
      echo -e "$gbInfo find $preLogName.tar.xz, not tar again"
      continue
    fi

    tar -cvf $preLogName.tar $logFile
    if [ $? -ne 0 ];then
      echo -e "$gbError \"tar -cvf $preLogName.tar $logFile\" error"
      continue
    fi

    if [ $gbXzNew -eq 1 ];then
      xz -T 0 -z $preLogName.tar
      if [ $? -ne 0 ];then
        echo -e "$gbError \"xz -T 0 -z $preLogName.tar\" error"

        xz -z $preLogName.tar
        if [ $? -ne 0 ];then
          echo -e "$gbError \"xz -z $preLogName.tar\" error" 
          continue
        else
          echo -e "$gbError \"xz -z $preLogName.tar\" ok" 
          gbXzNew=0
        fi
      else
        echo -e "$gbInfo \"xz -T 0 -z $preLogName.tar\" ok"
      fi
    else
      xz -z $preLogName.tar
      if [ $? -ne 0 ];then
        echo -e "$gbError \"xz -z $preLogName.tar\" error" 
        continue
      else
        echo -e "$gbError \"xz -z $preLogName.tar\" ok" 
      fi
    fi
  done

  return 1

}


make_tar_log
exit $?


