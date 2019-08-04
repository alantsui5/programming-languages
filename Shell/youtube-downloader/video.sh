#library
pip3 install youtube-dl &>/dev/null
brew list ffmpeg &>/dev/null || brew install ffmpeg &>/dev/null

#video
mkdir temp
cd temp
name=$1
youtube-dl -f bestvideo[ext=mp4]+bestaudio[ext=m4a]/best "ytsearch:$name" --output "$name.%(ext)s"
mv "$name.mp4" ~/Movies
cd ../
rm -rf temp



