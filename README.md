# sankyo_with_elp_camera  

![elp_12mm_lens](https://github.com/vintagefilmography/sankyo_with_elp_camera/assets/48537944/554805cf-1629-40a3-961b-dbabc2f4c8b9)

This project is based on a Sankyo projector and ELP camera.  
Parts:  
Sankyo1000 projector  
The camera used is the usb ELP model ELP-USBFHD04H-FV. It uses an AR0330 sensor with 1080P resolution.  
Light  
https://www.amazon.com/dp/B098W63FJ5...roduct_details  
Here is the result:  
[https://drive.google.com/file/d/1i-V...usp=share_link](https://drive.google.com/file/d/1_k86P1xBqTre0maZQDL-aEWelFFEkU7V/view?usp=sharing)  

This was scanned with the projector speed set to minimum which turns out to be around 7 frames per second.  

## Projector Mods
The 3 blade shutter wheel has to be removed. This is a bit involved project and will not be detailed here at this time.
The heat shield and the fan shroud also have to be removed to provide enough space for the trigger components.  
Do not throw out any of the screws, you will need them later.
Replace the lamap with the LED light. You will have to 3D print the lamp bracket from the mechanical folder here.
It consists of two parts. Use 3mm screws. 
![image](https://github.com/vintagefilmography/sankyo_with_elp_camera/assets/48537944/1ad04802-b6a0-44d5-931e-b37786adcc31)  

Print the camera adapter and attach it to the camera using 2mm screws and nuts.
Remove the old lens by pulling out on the focus knob (spring loaded) and by sliding the lensout. 
Slide the ecamera assembly into the lens holder. Make sure to pull out on the focus knob during the process.
If the camera fit is too tight then just send the adapter cylinder with sand paper.  
Make sure thatt the part is cleaned dout properly after the process.  
Print the trigger clip.
![image](https://github.com/vintagefilmography/sankyo_with_elp_camera/assets/48537944/d1b65001-4008-4c6a-a58f-f7e946794a0c)  
The trigger clip shaps onto the shutter wheel shaft as illustrated below.  
![image](https://github.com/vintagefilmography/sankyo_with_elp_camera/assets/48537944/57ac097b-96cb-42f6-8b7b-f1334ac37d5b)  
The trigger will have to be aligned properly once the trigger board is in place.
Order the trigger  board by contacting Stan Jelavic. You can send thee provate message in the forum.  
https://8mmforum.film-tech.com/vbb/forum/film-to-digital-conversion/86933-sankyo-projector-with-webcam-7fps-hd-resolution-synchronous-capture  
If you decide to make your own then send a message to Stan for the schematic info.
Connect the Arduino to the triggeer board.  
![image](https://github.com/vintagefilmography/sankyo_with_elp_camera/assets/48537944/83f7389f-189d-4bb6-b61d-45b5ed046067)  
Slide the arduino from the front of the unit through the heatshield cutout towards the back of the unit.  
![image](https://github.com/vintagefilmography/sankyo_with_elp_camera/assets/48537944/8bda40eb-59da-433f-9c1a-64bef76344b8)  
Align the trigger tab with the optocoupler bt sliding the trigger clip along the shaft.  
Additional trigger advance adjustment will be needed later.  
Mount the ardduino board in the top section of the unit just underneath the termnal strip.  
![image](https://github.com/vintagefilmography/sankyo_with_elp_camera/assets/48537944/ff0861ba-896d-40b2-91b5-2a38d681b046)  
Make sure interconnect are dressed up nice and that theye are not interfering with any of the moving parts.  
Load thee film in.  
Advance the film manually by rotating the fan by pushing down on the fins.  
Adjust the trigger clip so that it is engaging the optocoupler roughly 10 degrees beefore the film starts moving down. 
This will have to be readjusted lated during capture so that it results in minimum flicker.  
Connect the arduino to the PC and program it with the arduino sw included here.  
Download cinecamV3 PC windows capture program from this site.  
Connect the arduino and the camera to the PC. Make sure that the trigger is not triggering the optocoupler  
since this could cause random mouse clicks.   
Run the cinecam program by executing the .exe file in the release directory.  


## Instructions

Download "3-H.264 USB Camera Testing software for Windows-20230606T131020Z-001.zip" file to your local directory. Unzip it and go into it.  
Then double click on H264_Preview.exe  
A window will open uo and should look like as shown: 
image
Select the camera image
Enable preview: image
The frame preview should be displayed. If you get the white screen only then the camera may need a reset. Just unplug the camera from the PC and
plug it back in.
image

Note: Make sure that there is no external light shining on the gate like a daylight from the window etc.   
Additional camera controls are available via options pulldown: image image and camera controls image
These can be left as is. Under some conditions manual exposure and manual white balance may work better.
The best way is to experiment with the settings to achiveve best results. Some additional info:
https://docs.arducam.com/UVC-Camera/Quick-Start-for-Different-Systems/Windows/

Once all of this is set, run capture.
image
Set the destination file path. Make sure to type the .avi after the file name.
image
Click OK. Do not have to change the file allocation size.
image
Press the power button to turn the unit off. Then turn the RUN switch on and press the power button again. The unit will run and the film capture will start.

Once the video is done, turn the RUN switch off and power the unit off.
The video will have duplicate frames and transitions in it.
The duplicates are transitions get cleaned up by the avisynth script. Here are instructions on how to run the script.

Postprocessing
The video will contain many duplicate frames and transitions.
It is easy to remove the duplicates and the transition frames by using the Avisynth remove_dups script.
The first step in getting the the script working is to get Avisynth from:
https://sourceforge.net/projects/avisynth2/
Here is the avisynth home page. You can skip it for now. It is just for your reference. http://avisynth.nl/index.php/Main_Page
Avisynth does not run as a standalone application. It is a tool that allows video editors and viewers to run the script.
The script is essentially a text file that contains avisynth commands for video processing.
One video tool that is very handy for video processing is called VirtualDub.
In addition to basic video processing, VirtialDub reads the avisynth script as well.
Download VirtualDub from here:
https://sourceforge.net/projects/vdfiltermod/files/
Run VirtualDub. Should get a window that looks like the following picture:
image

The video file obtained by the capture sw uses the H264 codec and cannot be processed directly by the dups
script. To get around this issue drag the video into virtual dub and save it using the lagarith codec or raw.
Raw obviously will take up more space. Now this saved file will be compatible with the dups script.

Go to the scripts directory and open up remove_dups.avs in any text editor like Notepad or any other text editor.
Change the source path in the script to point to your vdeo. Example:
film = "F:\canon\clip1_raw.avi"

Once done with the script, just drag the script file into the VirtualDub window.
After a minute or so the video first frame will be displayed.
At that point, set the video compression in the video pulldown and save the video.
In unlikely case that there are black frames in the resulting video, run the remove_black_frames.avs script included here Once this is completed the resulting video can be brought back into VirtualDub or DaVinci Resolve to do the final cut.

If the script reports issues with loading certain plugins the most likely reason is that the your window installation is missing some DLLs. Run avsmeter.exe. in command window. It is in the scripts directory. Run avsmeter.exe. in command window. It is in the scripts directory. avsmeter remove_dups.avs
avsmeter provides the report and may give you additional info why the script is not loading properly.
Here is an example of the report: AVSMeter 2.9.9.1 (x86), 2012-2020, (c) Groucho2004
AviSynth 2.60, build:Feb 20 2015 [03:16:45] (2.6.0.5)

Number of frames: 2170
Length (hh:mm:ss.ms): 00:02:00.556
Frame width: 1920
Frame height: 1080
Framerate: 18.000 (18/1)
Colorspace: YV12
Active MT Mode: 0

Frame (current | last): 292 | 2169
FPS (cur | min | max | avg): 10.48 | 0.206 | 16.92 | 7.286
Process memory usage: 617 MiB
Thread count: 4
CPU usage (current | average): 24.7% | 24.5%

Time (elapsed | estimated): 00:00:40.076 | 00:04:57.825

In some cases avsmeter may not be able to help you and it may not give additional info on why a perticular DLL in
not loading.
You can also try dependency walker then. https://www.dependencywalker.com/#:~:text=Dependency%20Walker%20is%20a%20free,diagram%20of%20all%20dependent%20modules.
Download the zip into a local folder and unzip it there.
Run dependds.exe by double clicking on it.
A window will open.
image
Do File->Open and open the DLL that has issues loading. You will get a bunch of errors. Most of these are no problem beecause the tool is old and dodes not
recognize the new calls. Go don to the bottom of the error list and you will notice different types of errors. For example:
HVSIFILETRUST.DLL
IESHIMS.DLL
PDMUTILITIES.DLL
You can search for DLL description and dwhere used but most likely these are used by
Microsoft redistrbutable package that is not loaded on your system.
https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170 Install the 2015-2022 version and see if this fixes your issue. Most likely it will. Some more details here:
https://forum.doom9.org/showthread.php?t=172793











run through getdups.avs Avisynth script. The script removed all transitions one 100%.
I used AMCap for capture and set the Sankyo projector to the minimum speed which runs just slightly higher than 5 FPS.
Did the getdups script and then horizontal flip and crop and that is about it.
If you already own a Sankyo projector this will cost you <$100.
It may be possible to do this mod with other brands if the front opening is wide enough.

A few downsides:
- The rez is a bit on a low side like 900x700 final crop but in my opinion that is fully acceptable for a medium quality film.
- AMCap capture sw has preview issues. The preview gets all garbled up but that does not impact the saved video. I tried several capture apps
but they all have some issues so I stayed with AMCap.

Will try to post the instructions in github within a few days.
