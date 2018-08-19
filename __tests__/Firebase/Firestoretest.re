open Jest;
open Expect;
open! Expect.Operators;

describe("Firestore", () => {
  let firebase = Firebase.initializeApp(BsFirebaseX.Setuptest.config);

  describe("Firestore", () => {
    let firestore = firebase |> Firebase.firestore;
    let options = Firebase.Firestore.options(~timestampsInSnapshots=true, ());

    test("should run with errors", () =>
      expect(() => firestore |> Firebase.Firestore.settings(~options=options)) |> not_ |> toThrow
    );
  });
});
