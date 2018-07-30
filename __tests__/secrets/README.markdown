# Secrets Folder

Please create a `firebase.json` file in this directory that looks something like:

```json
{
  "projectId": "[SOME-PROJECT-ID]",
  "databaseURL": "[SOME-FIREBASE-URL]"
}
```

In order to be able to run tests.

To ensure maximum quality in our bindings library, we want to run tests against the real thing, not just mocks of firebase