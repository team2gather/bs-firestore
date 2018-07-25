[@bs.deriving abstract]   
type config = {
  [@bs.optional] apiKey: string,
  [@bs.optional] authDomain: string,
  [@bs.optional] databaseURL: string,
  [@bs.optional] projectId: string,
  [@bs.optional] storageBucket: string,
  [@bs.optional] messagingSenderId: string
};

type t;
[@bs.module "firebase"] 
external initializeApp : (~config: config) => t = ""; 
[@bs.send]
external firestore : (t) => Firestore.t = ""; 