  # Images to film with ffmpeg
  ffmpeg -r 120 -f image2 -s 600x600 -i ../recording/images/screenshot_%00d.png  -vcodec libx264 -crf 25  -pix_fmt yuv420p ../recording/physics-simulation.mp4