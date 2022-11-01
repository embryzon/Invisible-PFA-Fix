# Small-Project

For People asking "why is PFA invisible???" Send them this software kek.




Was Piano From Above (PFA) working just fine but then suddenly it got invisible after reopening? Yea it's a bug, I believe.
  
  You should be able to fix it manually by
  1. Press WIN + R and type "%appdata%", then OK. This opens the AppData Folder.
  2. Go to "Piano From Above" folder" and open "Config.xml". You may open it on any text editor.
  3. Find MainLeft="X" (X is any integer and it may be a negative value that's why it is not showing in the foreground).
  4. Change the X value to "0"
  5 Do the same for MainTop="X"
  6. CTRL + S to save, then close the file.
  7. Open PFA. 
  
  Note that PFA should be closed when editing the Config.xml file.
  
Now, if it happens to you rarely or frequent and you are too lazy to change the values in Config.xml, you can use this program.
It does the same process as stated above just automatically. 

How to use it?
You can download the executable file => Close PFA => Run the downloaded executable file => Reopen PFA => Hope it works (do this step in 0.098798 seconds because things happens fast)
