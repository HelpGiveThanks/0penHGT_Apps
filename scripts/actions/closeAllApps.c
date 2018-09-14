September 10, 2018 17:03:34 0penHGT_Apps.fmp12 - closeAllApps -1-
actions: closeAllApps
#
#
Show Custom Dialog [ Message: "Close all open HGT Apps: libraries, ActionLog, BudgetPlanner, HeartWhisperer?"; Default Button:
“OK”, Commit: “Yes”; Button 2: “cancel”, Commit: “No” ]
If [ Get (LastMessageChoice) = 1 ]
Exit Application
End If
#
#
