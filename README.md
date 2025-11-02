# Test C++ Build Actions

This is a test project that builds a small C++ program in a
Debian container on an Ubuntu GitHub runner, and on a GitHub
runner VM on Windows.

Each workflow YAML file represents the app version of the upcoming
release, which in this demo case are `3.2.0` and `2.8.1` versions.

The `3.2.0` workflow file  builds a candidate for the next dot-zero
release, which would be branched into `3.2.x` for patch releases.

The `2.8.1` workflow on the `main` branch is necessary because
GitHub will not run a workflow file on a branch unless there is
one on the `main` branch, so it's a dummy file that exists only
for the purpose of surfacing the real workflow file on the `2.8.x`
branch.

Every time a release has been made, each respective workflow file
must be renamed, so the build numbers would be restarted from `1`
for the next target release.

For example, when `v2.8.0` was ready to be released, a branch
`2.8.x` was created, so some release work could be done on that 
branch, while the `main` branch can be re-targeted for the next
`v3.0.0` release. Once `2.8.0` has been released, the branch
`2.8.x` will be used for patch releases - `2.8.1`, `2.8.2`, etc.
