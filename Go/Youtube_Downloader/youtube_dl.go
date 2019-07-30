import goydl

youtubeDl := goydl.NewYoutubeDl()
youtubeDl.Options.Output.Value = "video.mp3"
youtubeDl.Options.ExtractAudio.Value = true
youtubeDl.Options.AudioFormat.Value = "mp3"

 // Or update the binary
 youtubeDl.Options.Update.Value = true

 // Optional, required if binary is not in $PATH
 //youtubeDl.YoutubeDlPath = "/path/to/youtube-dl"
 cmd, err := youtubeDl.Download("http://videosite.com/videoURL")

 if err != nil {
     log.Fatal(err)
 }

 fmt.Printf("Title: %s\n", youtubeDl.Info.Title)

  // Synchronously:
  cmd.Wait()
 
  // Asynchronously:
  defer cmd.Wait()