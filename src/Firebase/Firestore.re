/**
 * @moduledoc BsFirebaseX.Firebase.Firestore
 *
 * The firestore js code lives here:
 *
 * https://github.com/firebase/firebase-js-sdk/blob/master/packages/firestore-types/index.d.ts
 */

/**
 * Read the get-start guide on firestore
 *
 * https://firebase.google.com/docs/firestore/quickstart
 *
 * Thanks to the top quality software produced by
 * Google's rigorously hired top quality engineers,
 * we need to force a require for its side-effects
 */
[@bs.module] external requireSideEffects : unit = "firebase/firestore";
let _ = requireSideEffects;

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L801
 */
type t;

/**
 * Firestore settings can be found on the google site
 *
 * https://firebase.google.com/docs/reference/js/firebase.firestore.Settings
 *
 * To avoid confusion with the function name `settings`,
 * I'm calling this field `options` instead of settings
 * as otherwise we'd have a name conflict with the `settings`
 * function below
 */
[@bs.deriving abstract]
type options = {
  [@bs.optional] timestampsInSnapshots: bool
};

/**
 * Here, we are sending the `settings` method onto the
 * `firestore` instance with an optional additional options.
 * Read about how bucklescript does that here:
 *
 * https://bucklescript.github.io/docs/en/function
 */
[@bs.send] external settings : (t, ~options: options = ?) => unit = "";

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L830
 */
[@bs.send] external enablePersistence : (t) => Js.Promise.t(unit) = "";

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L862
 */
[@bs.send] external collection : (t, ~collectionPath: string) => CollectionReference.t = "";

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L871
 */
[@bs.send] external doc : (t, ~documentPath: string) => DocumentReference.t = "";

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L887
 *
 * @TODO: bind `runTransaction`
 */

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L895
 *
 * @TODO: bind `batch`
 */

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L900
 *
 * @TODO: bind `app`
 */

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L908
 *
 * @TODO: bind `enableNetwork`
 */

/**
 * https://github.com/firebase/firebase-js-sdk/blob/74c57cfabf40d85b4f1ce4f514ad39e7978846ec/packages/firebase/index.d.ts#L918
 *
 * @TODO: bind `disableNetwork`
 */
