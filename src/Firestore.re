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
let _ = requireSideEffects

type t;
module DocumentSnapshot {
  type t;
  [@bs.send] external data : t => Js.t('a) = "";
};
module DocumentReference {
  type t;
  [@bs.get] external id : t => string = "";
  [@bs.send] external get : (t) => Js.Promise.t(DocumentSnapshot.t) = "";
  [@bs.send] external set : (t, Js.t('a)) => unit = "";
};
module CollectionReference {
  type t;
  [@bs.send] external doc : (t, string) => DocumentReference.t = "";
  [@bs.send] external add : (t, Js.t('a)) => Js.Promise.t(DocumentReference.t) = "";
};
[@bs.send] external collection : (t, string) => CollectionReference.t = "";


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
