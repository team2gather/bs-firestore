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
[@bs.send] external settings : (t, Js.t('a)) => unit = "";
