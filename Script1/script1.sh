#! /bin/bash

echo "script"


MY_NAME="Andrei_RUJAN"


cd ~/Documents/arujan


touch $MY_NAME.txt


for i in {0..9}
do
touch gitMessage$i
if [$i -eq 5]; then 
echo "$MY_NAME: my first script" >> gitMessage5
fi
done

git add $MY_NAME.txt


git commit -m "grep "$MY_NAME: my first script" "


for i in {1..10}
do
rm gitMessage$i
done