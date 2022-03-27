#!/bin/bash

LOGFILE=./log.txt

echo "Эта строка будет записана в файл \"$LOGFILE\"." 1>  $LOGFILE
echo "Эта строка будет добавлена в конец файла \"$LOGFILE\"." 1>> $LOGFILE

