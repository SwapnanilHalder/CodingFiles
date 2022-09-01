import React, { FC, useCallback, useState } from "react";
import { GoogleMap, Marker, useLoadScript } from "@react-google-maps/api";
import { observer } from "mobx-react-lite";

export const Map: FC = observer(() => {
  const { isLoaded, loadError } = useLoadScript({
    googleMapsApiKey: "", // ,
    // googleMapsClientId:"gme-movilizergmbh2"
    // ...otherOptions
  });

  const [map, setMap] = useState<google.maps.Map | null>();

  const onLoad = useCallback((loadedMap: google.maps.Map) => {
    setMap(loadedMap);
  }, []);

  const onUnmount = useCallback(() => {
    setMap(null);
  }, []);

  const position = {
    lat: 37.772,
    lng: -122.214,
  };

  return isLoaded ? (
    <div>
      <GoogleMap
        id="googleMap"
        mapContainerStyle={{
          height: "600px",
          width: "800px",
        }}
        zoom={5}
        //   onLoad={onLoad}
        //   onUnmount={onUnmount}
      >
        <Marker position={position} />
      </GoogleMap>
    </div>
  ) : (
    <button>Click Me!</button>
  );
  // </GoogleMap>
});
