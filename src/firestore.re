[@bs.deriving abstract]
type options = {
  projectId: string,
  keyFilename: string
};

type firestore;

[@bs.new]
[@bs.module]
external newFirestore : (~options: options) => firestore = "@google-cloud/firestore";

/* let firestore = newFirestore(options(~projectId="33", ~keyFilename="/path/to")); */

/* const document = firestore.doc('posts/intro-to-firestore'); */

/* external doc : firestore => firepath => document */