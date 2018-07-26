type t;
[@bs.module "firebase"] 
external initializeApp : Js.t({..}) => t = ""; 
[@bs.send]
external firestore : (t) => Firestore.t = ""; 