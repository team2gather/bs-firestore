/**
 * Firebase setup docs are here:
 *
 * https://firebase.google.com/docs/web/setup
 */

[@bs.deriving abstract]
type config = {
  [@bs.optional] apiKey: string,
  [@bs.optional] authDomain: string,
  databaseURL: string,
  projectId: string,
  [@bs.optional] storageBucket: string,
  [@bs.optional] messagingSenderId: string
};

type t;

[@bs.module "firebase"]
external initializeApp : config => t = "";

[@bs.send]
external firestore : (t) => Firestore.t = "";
