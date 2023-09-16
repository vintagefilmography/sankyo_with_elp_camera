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
Download cinecamv3.zip sw from here:  
https://drive.google.com/file/d/1sXQqYeeWrg85pbk6M5UWy_5RsJAFmLkf/view?usp=sharing  
Run the .exe file in release dir.  
The main window will open.   
Set camera selection to 0 or 1 depending on your system. Have to move the slider to the right until the numbers show up.  
Then back off the slider to get the roght selection.  
Set fps to 18.
Set the output file destination.
Set width to 1500    Makae sure not to make mistakes here. Backspace dodes not work. Restart program if necessary.  
Set height to 1000 Same as above. Backspace edoes nott work.  
Press Start. The preview window will open up. Click Capture button. The output preview window will open up.
Leave the cursor on the capture button and run the projector on lowest speed.  
If running at lowest speed (may have to reset the rheostat stop screew for lowest speed) use an external fan   
and point it to the rheostat to prevent ot from overheating.  
Altenatively install a 150 Ohm 100W resistor in series with the rheostat slider terminal.  
That shouldd give you a nice low FPS range 5-10 FPS.  
Once done with the capture disconneect the arduino to prevent the mouse clicks. 
Click the Stop button. Make sure not to click on the Start button. That wowuld erase output file.
Once you click on the Stop button, rename the output file and  then you are done. 

Postprocessing

Avisynth can be used for some postporcessig.  Get Avisynth from:
https://sourceforge.net/projects/avisynth2/
Here is the avisynth home page. You can skip it for now. It is just for your reference. http://avisynth.nl/index.php/Main_Page
Avisynth does not run as a standalone application. It is a tool that allows video editors and viewers to run the script.
The script is essentially a text file that contains avisynth commands for video processing.
One video tool that is very handy for video processing is called VirtualDub.
In addition to basic video processing, VirtialDub reads the avisynth script as well.
Download VirtualDub from here:
https://sourceforge.net/projects/vdfiltermod/files/  

Once done with the script, just drag the script file into the VirtualDub window.
After a minute or so the video first frame will be displayed.
In the video pulldown you can import filers for cropping, flipping horizontally etc.
At that point, set the video compression in the video pulldown and save the video.
