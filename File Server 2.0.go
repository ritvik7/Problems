package main

import (
  //"fmt"
  "flag"
  "html/template"
  "log"
  "net/http"
  )

  var addr = flag.String("addr", ":1200", "http service address")

  var templ = template.Must(template.New("index.html").ParseFiles("index.html"))
  var temp2 = template.Must(template.New("wrong.html").ParseFiles("wrong.html"))

  func main() {
    flag.Parse()

    http.Handle("/asdf/", http.StripPrefix("/asdf/",http.FileServer(http.Dir("css"))))
    http.Handle("/page/", http.HandlerFunc(QR))
    http.Handle("/", http.NotFoundHandler())
    http.Handle("/file/", http.HandlerFunc(Q))
    go http.Handle("/google/", http.RedirectHandler("http://www.google.com",307))
    //http.Handle("/google",http.TimeoutHandler(http.RedirectHandler("http://www.google.com",307),time.Microsecond,"Too Slow!"))
    err := http.ListenAndServe(*addr, nil)
    if err != nil {
      log.Fatal("ListenAndServe:", err)
    }
  }

  func QR(w http.ResponseWriter, req *http.Request) {
    log.Println("request:", req.URL)
    templ.ExecuteTemplate(w,"index.html",nil)
  }
  func Q(w http.ResponseWriter, req *http.Request) {
    temp2.ExecuteTemplate(w,"wrong.html",nil)
  }

