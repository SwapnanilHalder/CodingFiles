import React from 'react'
import TodoItem from './TodoItem'
import {Card, Button} from 'react-bootstrap'

const Todos = (props) => {
  return (
    <div className='container'>
      <h3 className='text-center my-3'>Todos List</h3>
      {
        props.todos.length !== 0 ? <></> : 
          <Card>
            <Card.Header>No Todos to display</Card.Header>
            <Card.Body>
              <Card.Text>
                To reload the page, click this button
              </Card.Text>
              <Button variant="primary">Reload</Button>
            </Card.Body>
          </Card>
      }
      {
        props.todos.map((x) => {
          return <TodoItem todo={x} key={x.sno} onDelete={props.onDelete}/>
        })
      }
    </div>
  )
}

export default Todos
