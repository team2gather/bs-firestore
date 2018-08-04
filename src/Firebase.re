module GeoPoint {
    type t;
    [@bs.new][@bs.module "firebase"][@bs.scope ("firestore")] external instance : (float, float) => t = "GeoPoint";
};

type t;
[@bs.module "firebase"] external initializeApp : Js.t({..}) => t = ""; 
[@bs.send] external firestore : (t) => Firestore.t = ""; 

