type t;
[@bs.module "firebase"] 
external initializeApp : Js.t('a) => t = ""; 
[@bs.send]
external firestore : (t) => Firestore.t = ""; 