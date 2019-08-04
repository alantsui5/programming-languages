#!/bin/sh

#  youtube-dl.sh
#  
#
#  Created by Alan on 11/3/2019.
#
while true;do
    read -p "Downlaod audio or video: " type
    if [[ "$type" == "v" ]] || [[ "$type" == "video" ]] || [[ "$type" == "a" ]] || [[ "$type" == "audio" ]];then
        break
    fi
done
read -p "The Name of clip: " link
if [[ "$type" == "v" ]] || [[ "$type" == "video" ]]; then
sh video.sh "$link" &>/dev/null
else
echo "Downloading...."
sh music.sh "$link" &>/dev/null
echo "Finished"
fi
