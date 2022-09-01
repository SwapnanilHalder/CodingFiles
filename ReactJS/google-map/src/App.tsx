import React, { useState } from "react";
import logo from "./logo.svg";
import { Map } from "./Map";
import { NormalDiv } from "./NormalDiv";

function App() {
  const [on, setOn] = useState(false);
  return (
    <>
    <Map/>
      {/* <button
        onClick={() => {
          setOn(!on);
        }}
      >
        Click Me!
      </button>
      <div/>
      <div>
        {
          on ?
          <div>
            <Map/>
          </div> :
          <div>
            <NormalDiv/>
          </div>
        }
      </div> */}
    </>
  );
}

export default App;
