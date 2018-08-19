type t;
[@bs.get] external id : t => string = "";
[@bs.send] external get : (t) => Js.Promise.t(DocumentSnapshot.t) = "";
[@bs.send] external set : (t, Js.t('a)) => unit = "";
