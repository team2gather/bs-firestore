open Jest;
open Expect;
open! Expect.Operators;

describe("Firestore", () => {
  let firebase = Firebase.initializeApp(Setuptest.config);

  describe("Firestore", () => {
    let firestore = firebase |> Firebase.firestore;
    let options = Firestore.options(~timestampsInSnapshots=true, ());

    test("should run with errors", () =>
      expect(() => firestore |> Firestore.settings(~options=options)) |> not_ |> toThrow
    );
  });
});
