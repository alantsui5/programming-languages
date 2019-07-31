package main

import (
	"encoding/json"
	"log"
	"math/rand"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
)

//Movie class (Model)
type movie struct {
	ID        string `json:"ID"`
	Title     string `json:"title"`
	MainActor *actor `json:"mainactor"`
}

type actor struct {
	Firstname string `json:"firstname"`
	Lastname  string `json:"lastname"`
}

// Main Movie list
var movies []movie

//Get full movie list
func getMovies(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(movies)
}

// Get single Movie
func getMovie(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	params := mux.Vars(r) // Gets params
	// Loop through books and find one with the ID from the params
	for _, item := range movies {
		if item.ID == params["ID"] {
			json.NewEncoder(w).Encode(item)
			return
		}
	}
	json.NewEncoder(w).Encode(&movie{})
}

// Add movie
func addMovie(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	var book movie
	_ = json.NewDecoder(r.Body).Decode(&book)
	book.ID = strconv.Itoa(rand.Intn(100000000)) // Mock ID - not safe
	movies = append(movies, book)
	json.NewEncoder(w).Encode(book)
}

// Update movies
func updateMovie(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	params := mux.Vars(r)
	for index, item := range movies {
		if item.ID == params["ID"] {
			movies = append(movies[:index], movies[index+1:]...)
			var book movie
			_ = json.NewDecoder(r.Body).Decode(&book)
			book.ID = params["ID"]
			movies = append(movies, book)
			json.NewEncoder(w).Encode(book)
			return
		}
	}
}

// Delete movie
func deleteMovie(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	params := mux.Vars(r)
	for index, item := range movies {
		if item.ID == params["ID"] {
			movies = append(movies[:index], movies[index+1:]...)
			break
		}
	}
	json.NewEncoder(w).Encode(movies)
}

func main() {
	//Init Router
	r := mux.NewRouter()

	//Database
	//Test:These is hard coded data, will then write test alter
	movies = append(movies, movie{ID: "1", Title: "Forrest Gump", MainActor: &actor{Firstname: "Tom", Lastname: "Hanks"}})
	movies = append(movies, movie{ID: "2", Title: "Hotel Del Luna", MainActor: &actor{Firstname: "Ji-eun", Lastname: "Lee"}})

	// Route Handlers /Endpoints
	r.HandleFunc("/api/movies", getMovies).Methods("GET")
	r.HandleFunc("/api/movies/{ID}", getMovie).Methods("GET")
	r.HandleFunc("/api/movies", addMovie).Methods("POST")
	r.HandleFunc("/api/movies/{ID}", updateMovie).Methods("PUT")
	r.HandleFunc("/api/movies/{ID}", deleteMovie).Methods("DELETE")

	//Ports
	log.Fatal(http.ListenAndServe("0.0.0.0:8000", r))
}
