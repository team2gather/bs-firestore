[@bs.deriving abstract]
type config = {
  projectId: string,
  databaseURL: string
};

type t;

[@bs.module "firebase"] 
external initializeApp : config => t = ""; 

[@bs.send]
external firestore : (t) => Firestore.t = ""; 