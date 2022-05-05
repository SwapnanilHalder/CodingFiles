package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"

	// "github.com/gin-gonic/gin"
	"github.com/go-chi/chi"
)

func main() {
	fmt.Println("Starting server")

	router := chi.NewRouter()
	router.Get("/api/getExamples", getHandler)
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func getHandler(w http.ResponseWriter, r *http.Request) {
	// fmt.Fprintln(w, "Hi my bitch")
	json.NewEncoder(w).Encode("Hello There...")
}
