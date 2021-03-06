September 10, 2018 16:55:39 0penHGT_Apps.fmp12 - gotoOtherLibrary -1-
libraries: gotoOtherLibrary
#
#!!!!!!!!!! NOTE !!!!!!!!!!!!!
#!!!!!!!!!! NOTE !!!!!!!!!!!!!
#!!!!!!!!!! NOTE !!!!!!!!!!!!!
#This script uses similar logic, to the other
#apps. If you change it here, check it in the
#other apps too.
#
#Because this portal is to external database it is
#essential to get this record's path info for use in
#other script steps.
Set Variable [ $path; Value:MemorySwitch::path ]
Set Variable [ $name; Value:MemorySwitch::name ]
#
#Open using this url on iPad/iPhone.
If [ Get ( SystemPlatform ) = 3 ]
Set Error Capture [ On ]
#
Set Field [ MemorySwitch::currentLibraryName; $name ]
Open URL [ "fmp://%7e/" & Substitute ( MemorySwitch::name ; " " ; "%20" ) ]
[ No dialog ]
#
If [ Get ( LastError ) ≠ 0 ]
#If the library fails to open inform user why.
Show Custom Dialog [ Message: "The library you selected is not available on this device or its name was changed so its
shortcut is being deleted."; Default Button: “OK”, Commit: “No” ]
#Tell user how to add a library.
Show Custom Dialog [ Message: "You can add it back after locating it using the add button."; Default Button: “OK”, Commit:
“No” ]
Delete Portal Row
[ No dialog ]
Exit Script [ ]
End If
#
End If
#
#If library path is blank (which should only happen if
#admin adds library manually with path), then delete
#this library name from the list.
If [ MemorySwitch::path = "" ]
Show Custom Dialog [ Message: "This library file cannot be found under the name " & MemorySwitch::name & ". It will be
removed from this list. You can add it back after locating it using the add button."; Default Button: “OK”, Commit: “No” ]
Delete Portal Row
[ No dialog ]
Exit Script [ ]
End If
#
#Select the current library windows if open and selected.
If [ MemorySwitch::currentLibraryPath = $path ]
Select Window [ Name: GetValue ( WindowNames ( Case ( Get ( SystemPlatform ) = - 2 ;
MemorySwitch::name ;
MemorySwitch::name ) ) ; 1 ) ]
Select Window [ Name: GetValue ( WindowNames ( Case ( Get ( SystemPlatform ) = - 2 ;
MemorySwitch::name ;
MemorySwitch::name ) ) ; 2 ) ]
Select Window [ Name: MemorySwitch::currentLibraryWIndows ]
End If
#
#There is no harm in leaving multiple libraries
#open, so just open the selected one if
#available. NOTE: There are too many
#different window names that could be open
#for a library, and further testing needs to be
#done make sure all are accounted for before
#closing an open library is a sure thing!
If [ MemorySwitch::currentLibraryPath ≠ $path or Get (LastError) = 112 ]
Set Field [ MemorySwitch::currentLibraryPath; $path ]
Set Field [ MemorySwitch::currentLibraryName; $name ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (MemorySwitch::path ; " " ; "%20" ) ;
Substitute ( Substitute ( MemorySwitch::path ; "file:/" ; "file://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
End If
#
#If the path stored for the selected library failed to open
#the library, then that library is no longer there or its
#name has been changed, so delete it from the
#library list.
If [ Get (LastError) = 5 ]
Show Custom Dialog [ Message: "This library file cannot be found under the name " & MemorySwitch::name & ". It will be
removed from this list. You can add it back after locating it using the add button."; Default Button: “OK”, Commit: “No” ]
#
#This seems to work if just the portal row is
#deleted. Further testing is needed to confirm.
Delete Portal Row
[ No dialog ]
Exit Script [ ]
End If
#
#Set selected path and name to current name
#and path.
Set Field [ MemorySwitch::currentLibraryPath; $path ]
Set Field [ MemorySwitch::currentLibraryName; $name ]
#
#
