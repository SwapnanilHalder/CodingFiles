import './App.css';
import React, { useState } from 'react';
import Header from './MyComponents/Header.js';
import Todos from "./MyComponents/Todos.js";
import Footer from "./MyComponents/Footer.js";

function App() {
  const onDelete = (x) => {
    console.log('I am onDelete on the todo item :', x);
    updateTodos(items.filter((e)=> {
      return e !== x;
    }))
  } 
  const [items, updateTodos] = useState(
    [{
      sno: 1,
      title: "Go to the Market",
      desc: "We need more supplies",
    },
    {
      sno: 2,
      title: "Go to the Mall",
      desc: "Today is very hot",
    },
    {
      sno: 3,
      title: "Go to the Ghat",
      desc: "I like to travel in boat",
    },]
  );

  return (
    <>
      <Header title={"My Todos List"} searchBar={true}/>
      <Todos todos={items} onDelete={onDelete}/>
      <Footer/>
    </>
  );
}

export default App;