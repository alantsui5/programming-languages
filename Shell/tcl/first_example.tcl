#include Library
package require Tk
#Set the title
wm title . "Feet to Meters"
#set up frame: primary widget to contain everything
grid [ttk::frame .c -background "black" -padding "3 3 12 12"] -column 0 -row 0 -sticky nwes
#expand cell when resize
grid columnconfigure . 0 -weight 1 grid rowconfigure . 0 -weight 1
#Give text input and assign var
grid [ttk::entry .c.feet -width 7 -textvariable feet] -column 2 -row 1 -sticky we
#Give meters a place(label) to hold
grid [ttk::label .c.meters -textvariable meters] -column 2 -row 2 -sticky we
#Execute button in row3 col3
grid [ttk::button .c.calc -text "Calculate" -command calculate] -column 3 -row 3 -sticky w
#Add label feet after textbox
grid [ttk::label .c.flbl -text "feet"] -column 3 -row 1 -sticky w
#Add another label
grid [ttk::label .c.islbl -text "is equivalent to"] -column 1 -row 2 -sticky e
#Add another label
grid [ttk::label .c.mlbl -text "meters"] -column 3 -row 2 -sticky w
#Add padding to each grid child
foreach w [winfo children .c] {grid configure $w -padx 5 -pady 5}
#Put focus to input field
focus .c.feet
#bind submit = enter
bind . <Return> 
#calculation
proc calculate {} {  
   if {[catch {
       set ::meters [expr {round($::feet*0.3048*10000.0)/10000.0}]
   }]!=0} {
       set ::meters ""
   }
}
