; -- Sample2.iss --
; Same as Sample1.iss, but creates its icon in the Programs folder of the
; Start Menu instead of in a subfolder, and also creates a desktop icon.

; SEE THE DOCUMENTATION FOR DETAILS ON CREATING .ISS SCRIPT FILES!

[Setup]
AppName='Bulls and cows' game
AppVerName='Bulls and cows' game version 1.1
AppCopyright=Copyright (C) 1998-1999 Pavel Skrylev
DefaultDirName={pf}\BNC
DisableProgramGroupPage=yes
; ^ since no icons will be created in "{group}", we don't need the wizard
;   to ask for a group name.
UninstallDisplayIcon={app}\bnc.exe

[Files]
Source: "bnc.exe"; DestDir: "{app}"

[Icons]
Name: "{commonprograms}\'Bulls and cows' game"; Filename: "{app}\bnc.exe"
Name: "{userdesktop}\'Bulls and cows' game"; Filename: "{app}\bnc.exe"
