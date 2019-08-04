#library
pip3 install youtube-dl &>/dev/null
brew list ffmpeg &>/dev/null || brew install ffmpeg &>/dev/null

name=$1
mkdir temp
cd temp

youtube-dl -f bestaudio[ext=m4a] "ytsearch:$name" --output "%(title)s.%(ext)s"

mv *.m4a ~/Music/iTunes/iTunes\ Media/Automatically\ Add\ to\ iTunes.localized/

cd ../
rmdir temp
