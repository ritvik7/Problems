package main

import (
  "flag"
  "html/template"
  "log"
  "net/http"
  )

  var addr = flag.String("addr", ":1400", "http service address")

  var templ = template.Must(template.New("index.html").ParseFiles("index.html"))

  func main() {
    flag.Parse()
    http.Handle("/css/", http.HandlerFunc(handleAsset))
    http.Handle("/", http.HandlerFunc(QR))
    err := http.ListenAndServe(*addr, nil)
    if err != nil {
      log.Fatal("ListenAndServe:", err)
    }
  }

  func QR(w http.ResponseWriter,   req *http.Request) {
    log.Println("request:", req.URL)
    templ.ExecuteTemplate(w,"index.html",nil)
  }

func handleAsset(w http.ResponseWriter,   req *http.Request)  {
  log.Println("asset request:", req.URL)
}

