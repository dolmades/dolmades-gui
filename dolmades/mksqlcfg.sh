#!/bin/bash

cat config.sql > config.sql.tmp
for repl in $(cat config.sql | tr ' ' '\n' | awk '/%.*%/{printf("%s\n", gensub(".*%(.*)%.*","%\\1%",$0));}' | sort -u | awk '{system("echo "$1"|sha256sum"); print $1; }' | awk '{if (NF==2) sum=$1; if (NF==1) {id=$1; printf("s/%s/'\''%s'\''/g\n",id,sum);}}' ); do 
     sed -i $repl config.sql.tmp
done
