import React from 'react';
import { Form, Button, Navbar, Nav, Container, FormControl } from "react-bootstrap";
import PropTypes from 'prop-types'

function Header(props) {
  return (
    <div>

<Navbar bg="light" expand="lg">
  <Container fluid>
    <Navbar.Brand href="#">{props.title}</Navbar.Brand>
    <Navbar.Toggle aria-controls="navbarScroll" />
    <Navbar.Collapse id="navbarScroll">
      <Nav
        className="me-auto my-2 my-lg-0"
        style={{ maxHeight: '100px' }}
        navbarScroll
      >
        <Nav.Link href="#action1">Home</Nav.Link>
        <Nav.Link href="#action2">About</Nav.Link>
      </Nav>
      {props.searchBar?<Form className="d-flex">
        <FormControl
          type="search"
          placeholder="Search"
          className="me-2"
          aria-label="Search"
        />
        <Button variant="outline-success">Search</Button>
      </Form>:""}
    </Navbar.Collapse>
  </Container>
</Navbar>

    </div>
  )
}
export default Header;

Header.defaultProps = {
  title : "No Title Given",
  searchBar: true,
}

Header.propTypes = {
  title: PropTypes.string.isRequired,
  searchBar: PropTypes.bool,
}
