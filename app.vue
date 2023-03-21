<script setup lang="ts">
const input = ref('')

const query = computed(() => ({
  input: input.value
}))

const { data } = useFetch('/api/reverse', {
  query,
  immediate: false,
  watch: [query]
})
</script>


<template>
  <div>
    <h1>revC</h1>
    <input v-model="input" />
    <pre>input: {{ input }}</pre>
    <pre>data: {{ data }}</pre>
  </div>
</template>
