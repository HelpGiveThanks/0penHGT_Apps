September 10, 2018 16:59:44 0penHGT_Apps.fmp12 - start -1-
actions: start
Set Window Title [ Current Window; New Title: "All Apps" ]
Go to Layout [ “startMemorySwitch” (MemorySwitch) ]
#
#Recalculate help filepath. To do this,
#filemaker must create a new record which
#can then be deleted. The help filepath is a
#global record, and that means the
#recaclucated path will now be used for all
#memoryswitch records and scripts needing
#this path.
New Record/Request
Delete Record/Request
[ No dialog ]
#
#
Go to Layout [ “allApps” (tempSetup) ]
Show All Records
Delete All Records
[ No dialog ]
New Record/Request
Go to Field [ ]
Adjust Window
[ Resize to Fit ]
Show/Hide Menubar
[ Hide ]
Show/Hide Toolbars
[ Hide ]
Show/Hide Text Ruler
[ Hide ]
#
#Show regular menus if Admin logs in and set
#print page size for one long page so when
#generating PDFs for GitHub a script's title will
#be shown only once (it shows multiple times if
#the script takes several letter size pages).
If [ Get ( AccountName ) = "Admin" ]
Show/Hide Toolbars
[ Hide ]
Install Menu Set [ “[Standard FileMaker Menus]” ]
Print Setup [ Orientation: Portrait; Paper size: 8.5" x 1000" ]
[ Restore; No dialog ]
Else
Show/Hide Toolbars
[ Lock; Hide ]
Install Menu Set [ “HGT” ]
Print Setup [ Orientation: Portrait; Paper size: 8.5" x 11" ]
[ Restore; No dialog ]
End If
#
#If no libraries are detected then tell user why.
If [ MemorySwitch::name = "" ]
#
#If on an iOS device ...
If [ Get ( SystemPlatform ) = 3 ]
#
#Tell user how to add a library.
Show Custom Dialog [ Message: "To add libraries to the All Apps menu, 1) click the circled v in the upper-left corner, and 2)
select launch center. 3) In the bottom of the next window, click Device. 4) Now click on any library file to add it to the All
Apps menu."; Default Button: “OK”, Commit: “Yes” ]
#
#Go to field is needed to insure first library
#added shows up after adding it.
Go to Field [ ]
#
#Halt the script so that the pause script
#command is disabled which will allow the user
#to click the blue circled arrow in the upper-
#left-hand corner of an iOS device.
Halt Script
#
#
#If on an desktop/laptop computer ...
Else
#
#Tell a user how to add a library.
Show Custom Dialog [ Message: "To add libraries to the All Apps menu, click the add button, and then double-click on any
library files that you wish to add (in the folder that will open after clicking the add button)."; Default Button: “OK”, Commit:
“Yes” ]
End If
End If
#
#Refresh to the window to update the libraries
#list, otherwise it might show libraries that have
#been deleted.
Refresh Window
#
