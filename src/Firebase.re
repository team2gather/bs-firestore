/**
 * Firebase setup docs are here:
 *
 * https://firebase.google.com/docs/web/setup
 *
 * and source code lives in this repo:
 *
 * https://github.com/firebase/firebase-js-sdk/tree/master/packages/firebase.
 *
 * In general, functions and whatnot are copied over from their
 * index.d.ts files whenever possible
 *
 * https://github.com/firebase/firebase-js-sdk/blob/master/packages/firebase/index.d.ts
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

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L126
 */
type t;

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L114
 */
[@bs.module "firebase"]
external initializeApp : config => t = "";

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L134
 */
[@bs.send]
external firestore : (t) => Firestore.t = "";
