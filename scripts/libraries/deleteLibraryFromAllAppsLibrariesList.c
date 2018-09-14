September 10, 2018 16:58:59 0penHGT_Apps.fmp12 - deleteLibraryFromAllAppsLibrariesList -1-
libraries: deleteLibraryFromAllAppsLibrariesList
#
#
Show Custom Dialog [ Message: "Delete this library from the list? NOTE: This action will not delete the library itself, only your ability
to open it from this list. You can always add it back by clicking the add button."; Default Button: “cancel”, Commit: “Yes”; Button 2:
“delete”, Commit: “No” ]
If [ Get (LastMessageChoice) = 2 ]
Delete Portal Row
[ No dialog ]
#
#Next two commands are essential for
#refreshing the portal so it does not show the
#library that was just deleted.
Go to Field [ ]
Refresh Window
End If
#
#
