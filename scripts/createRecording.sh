  # Images to film with ffmpeg
  ffmpeg -r 60 -f image2 -s 1920x1080 -i ../recording/images/screenshot_%00d.png  -vcodec libx264 -crf 25  -pix_fmt yuv420p ../recording/physics-simulation.mp4