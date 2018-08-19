type t;
[@bs.send] external doc : (t, string) => DocumentReference.t = "";
[@bs.send] external add : (t, Js.t('a)) => Js.Promise.t(DocumentReference.t) = "";
