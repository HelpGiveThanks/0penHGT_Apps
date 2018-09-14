September 10, 2018 16:59:31 0penHGT_Apps.fmp12 - help -1-
help: help
#
#
// If [ MemorySwitch::name = "" ]
Show Custom Dialog [ Message: "Most of these buttons open an application, library, or website when clicked, with the exception
of the add, closeAll, X, and ? buttons."; Default Button: “OK”, Commit: “Yes” ]
Show Custom Dialog [ Message: "Click the add and X buttons to add and delete libraries from the list of libraries that you can
open from the All Apps Libraries list. Click closeAll to quit all HGT Apps, and ? to see this help."; Default Button: “OK”,
Commit: “Yes” ]
Show Custom Dialog [ Message: "NOTE: Periodically check the HelpGiveThanks website to insure that you are using the most
current version of each application and library. Version numbers are displayed vertically."; Default Button: “OK”, Commit:
“Yes” ]
// Else
// Show Custom Dialog [ Message: "Click any button to open that application, library, or website. Click the add button to add
libraries to the list of libraries that you can open."; Default Button: “OK”, Commit: “Yes” ]
// End If
#
#
