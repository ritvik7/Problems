package main

import (
  "log"
  "net/http"
  )

  func main() {
    mux := http.NewServeMux()

    rh := http.RedirectHandler("http://example.org", 307)
    mux.Handle("/", rh)

    log.Println("Listening...")
    http.ListenAndServe(":3000", mux)
  }
