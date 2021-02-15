#!/bin/bash

cd /etc/nginx/sites-available

if  grep -qiw 'autoindex off' default 
then
   sed -i --follow-symlinks 's/autoindex off/autoindex on/g' default
   echo 'autoindex set to on'
else
   sed -i --follow-symlinks 's/autoindex on/autoindex off/g' default
   echo 'autoindex set to off'
fi

cd / 
nginx -s reload