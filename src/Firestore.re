module QuerySnapshot {
    type t;
    [@bs.get] external exists : t => bool = "";
    [@bs.get] external docs : t => array('a) = "";
    [@bs.send] external docChanges : t => array('a) = "";
};
module DocumentSnapshot {
    type t;
    [@bs.get] external exists : t => bool = "";
    [@bs.send] external data : t => Js.t({..}) = "";
};
module DocumentChange {
    type t;
    [@bs.get] external doc : t => DocumentSnapshot.t = "";
};
module DocumentReference {
    type t;
    [@bs.get] external id : t => string = "";
    [@bs.send] external get : (t) => Js.Promise.t(DocumentSnapshot.t) = "";
    [@bs.send] external set : (t, Js.t({..})) => unit = "";
    /* ADD UPDATE */
    [@bs.send] external update : (t, Js.t({..})) => unit = ""; 
    [@bs.send] external onSnapshot : (t, 'a, 'b) => 'c = "";
};
module CollectionReference {
    type t;
    [@bs.send] external add : (t, Js.t({..})) => Js.Promise.t(DocumentReference.t) = "";
    [@bs.send] external onSnapshot : (t, 'a, 'b) => 'c = "";
};
type t;
[@bs.send] external collection : ('a, string) => CollectionReference.t = "";
[@bs.send] external doc : ('a, string) => DocumentReference.t = "";
[@bs.send] external settings : (t, Js.t({..})) => unit = "";
