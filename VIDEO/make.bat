if not exist "gameplay.mp4" %TOOL%\FFMPEG\bin\ffmpeg -y -i "ORIGINAL\gameplay.mp4" -ss 00:07 -to 06:44 -vf "crop=iw-656:ih:328:0" -c:v av1_nvenc -rc vbr -cq 24 -c:a libopus -b:a 128k "gameplay.mp4"
if not exist "gameplay_small.mp4" %TOOL%\FFMPEG\bin\ffmpeg -y -i "ORIGINAL\gameplay.mp4" -ss 00:10.5 -to 05:21 -vf "crop=iw-656:ih:328:0,scale=384:272" -c:v av1_nvenc -b:v 128k -preset p4 -c:a libopus -b:a 128k "gameplay_small.mp4"
if not exist "gameplay_small.avif" %TOOL%\FFMPEG\bin\ffmpeg -y -i "ORIGINAL\gameplay.mp4" -ss 00:10.5 -to 05:21 -vf "crop=iw-656:ih:328:0,scale=384:272" -c:v av1_nvenc -b:v 128k -preset p4 -an "gameplay_small.avif"
pause
