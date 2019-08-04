# resize the terminal in alpine linux
# Status: Not Done

# Current time
date
# Date formatting
date +%Y/%m/%d
# Output: 2019/05/28
date +%H:%M
# Output: 21:15

#Calender for a month
cal

# Calender for whole year
cal 2019

# Calender for September 2019
cal 9 2019

# Calculator
apk add bc
bc
2^2000

#Manual
apk add man
# See the locale settings
# Status: Not Supported
#locale

#change language and locale in terminal
LANG=en_US.utf8
export LC_ALL=en_US.utf8