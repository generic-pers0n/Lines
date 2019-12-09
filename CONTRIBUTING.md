# Contributing

With the availability of the source code of Lines on GitHub comes the opportunity to contribute to Lines. However, when you contribute, you agree to these guidelines. The following guidelines are shown below.

**NOTE: You do NOT need to know how to code in order for you to contribute to Lines.**

## Branches
You'll see several branches in the Lines repository: `master`, `devel`, and `beta`. The `master` branch is the source code for the latest version of Lines. **DO NOT CONTRIBUTE DIRECTLY TO THIS BRANCH UNLESS OTHERWISE TOLD.** This is what the other branch, `devel`, is for. `devel` is for any changes of any kind, whether that's for Lines, liblines, or any documentation.

**NOTE: If you want to contribute to documentation, then you can go ahead and contribute the changes to the `master` branch.**

The `beta` branch is similar to the `devel` branch. However, this is for more stable releases of Lines, but aren't complete. In the `beta` branch, the code is guaranteed to compile, although not necessarily without errors.

In the `beta` branch, you **cannot** any new files **UNLESS** they are not related to the program. New features will not be accepted. Existing features cannot be removed, but some functionallity can be removed.

When you want to merge the `devel` branch into the `beta` branch, the code **must** compile at least to an executable (since the `beta` branch is meant for code guaranteed to compile). If the code is not able to compile at all, then `devel` won't be merged.

Whenever a new version of Lines is released, you can go ahead and merge `master` into `beta` and `devel`. If you want, you can merge `beta` into `devel` for whatever reason. Generally, you should do this after a new stable version of Lines is released.

If you want to create your own seperate branch for a feature you are proposing, you can do so, and it will be reviewed. For the most part, some features or changes will always be accepted, but this doesn't mean that all features will be accepted. During the review, anybody can contribute to that branch, but only if it's related to that feature.

### Merging a branch
When there's a branch that's ready to be merged, you can go ahead and start a pull request, or go ahead and merge it. When you do, we'll review all the changes there is to look at. If approved, then your pull request may come to life.

**NOTE: If your pull request gets accepted, and your pull request is about merging the** `beta` **branch into the** `master` **branch, then that indicates you want to release a new version of Lines.**

## Adding new files
If you want to add a new file to Lines, then you may do so appropriately. Depending on what you add, this may count as a new major version for Lines. If it's something related to the program, then it will count as a new version of Lines as though this affects the program's functionallity. **You can only, however, add the file if there's work being done in the `devel` branch. Else the file(s) will be REJECTED if you try to do so**. If it's not related to the program (e.g. documentation), then it will not count as a new major verion.

## Documentation
If you want to change something about the documentation, then you can go ahead and contribute. You'll need to know some Markdown, which is extremely easy to learn (at least, the standard implementation is). To learn Markdown, visit [this link](https://www.markdowntutorial.com/).
