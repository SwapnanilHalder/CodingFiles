import React from 'react'
import {Button} from 'react-bootstrap'

const TodoItem = ({todo, onDelete}) => {
  return (
    <div>
      <h4>{todo.title}</h4>
      <p>{todo.desc}</p>
      <Button variant="danger" size="sm" onClick={() => {onDelete(todo)}}> Delete </Button>
    </div>
  )
}

export default TodoItem
